''' Medium '''
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [0 for _ in range(days[-1] + 1)]
        days_idx = 0
        for day in range(1, days[-1] + 1):
            if day != days[days_idx]:
                dp[day] = dp[day - 1]
            else:
                dp[day] = min(dp[max(0, day - 1)] + costs[0],
                              dp[max(0, day - 7)] + costs[1],
                              dp[max(0, day - 30)] + costs[2])
                days_idx +=1
        return dp[-1]