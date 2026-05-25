func checkValidString(s string) bool {
    cmin, cmax := 0, 0

    for _, c := range s {
        if c == '(' {
            cmin++
            cmax++
        } else if c == ')' {
            cmin = max(0, cmin - 1)
            cmax--
        } else {
            cmin = max(0, cmin - 1)
            cmax++
        }

        if cmax < 0 {
            return false
        }
    }

    return cmin == 0
}

