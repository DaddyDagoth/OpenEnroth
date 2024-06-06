#include <string>
#include <vector>
#include <set>
#include <unordered_set>

#include <ranges>

#include "Testing/Unit/UnitTest.h"

#include "Utility/String/Split.h"

static_assert(std::ranges::view<detail::SplitView>);
static_assert(std::ranges::viewable_range<detail::SplitView>);
static_assert(std::ranges::input_range<detail::SplitView>);

UNIT_TEST(StringSplit, SplitToVector) {
    std::vector<std::string_view> v;

    split("aa;bb;cc", ';', &v);
    std::vector<std::string_view> r0 = {"aa", "bb", "cc"};
    EXPECT_EQ(v, r0);

    split("ABC", ';', &v);
    std::vector<std::string_view> r1 = {"ABC"};
    EXPECT_EQ(v, r1);

    split("AB", 'B', &v);
    std::vector<std::string_view> r2 = {"A", ""};
    EXPECT_EQ(v, r2);

    split(";", ';', &v);
    std::vector<std::string_view> r3 = {"", ""};
    EXPECT_EQ(v, r3);

    split("", ';', &v);
    std::vector<std::string_view> r4 = {""};
    EXPECT_EQ(v, r4);
}

UNIT_TEST(StringSplit, ConverToContainer) {
    const char *s = "1;2;3";

    std::vector<std::string_view> v1 = split(s, ';');
    EXPECT_EQ(v1, std::vector<std::string_view>({"1", "2", "3"}));

    std::vector<std::string> v2 = split(s, ';');
    EXPECT_EQ(v2, std::vector<std::string>({"1", "2", "3"}));

    std::set<std::string_view> v3 = split(s, ';');
    EXPECT_EQ(v3, std::set<std::string_view>({"1", "2", "3"}));

    std::set<std::string> v4 = split(s, ';');
    EXPECT_EQ(v4, std::set<std::string>({"1", "2", "3"}));

    std::unordered_set<std::string_view> v5 = split(s, ';');
    EXPECT_EQ(v5, std::unordered_set<std::string_view>({"1", "2", "3"}));

    std::unordered_set<std::string> v6 = split(s, ';');
    EXPECT_EQ(v6, std::unordered_set<std::string>({"1", "2", "3"}));
}
