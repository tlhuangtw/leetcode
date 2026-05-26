func merge(intervals [][]int) [][]int {
    slices.SortFunc(intervals, func(i, j []int) int {
        if n := cmp.Compare(i[0], j[0]); n != 0 {
            return n
        }
        return cmp.Compare(i[1], j[1])
    })

    merged := make([][]int, 0, len(intervals))

    for _, interval := range intervals {
        n := len(merged)
        if n == 0 || merged[n-1][1] < interval[0] {
            merged = append(merged, interval)
        } else {
            merged[n-1][1] = max(merged[n-1][1], interval[1])
        }
    }

    return merged
}

