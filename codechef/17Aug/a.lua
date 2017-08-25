function solve ()
    local n = io.read ("*n")
    local a = {}
    for i = 1, n, 1 do
        a[i] = io.read ("*n")
    end

    local m = math.floor((n + 1) / 2)
    local is_rainbow = true
    for i = 1, m, 1 do
        if i == 1 and a[i] ~= 1 then
            is_rainbow = false
            break
        end

        if i == m and a[i] ~= 7 then
            is_rainbow = false
            break
        end

        if i > 1 and a[i] - a[i - 1] > 1 then
            is_rainbow = false
            break
        end

        if i > 1 and a[i] - a[i - 1] < 0 then
            is_rainbow = false
            break
        end

        if a[i] ~= a[n + 1 - i] then
            is_rainbow = false
            break
        end
    end
    io.write (is_rainbow and "yes" or "no", "\n")
end

function main ()
    local case_n = io.read ("*n")
    for case_i = 1, case_n, 1 do
        solve ()
    end
end

main ()
