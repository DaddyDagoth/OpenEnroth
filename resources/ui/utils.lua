---Convert a string to a boolean
---@param value string
---@return boolean
function tobool(value)
    return value ~= "false" and value ~= "0"
end

---Convert a variable ( most of the time a string ) to a number. in case of failure the default_value is returned
---@param amount any
---@param default_value number
---@return number
function tonumber_or(amount, default_value)
    amount = tonumber(amount)
    return amount and amount or default_value
end
