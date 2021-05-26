class meeting:
    def __init__(self, start, end, pos):
        self.start = start
        self.end = end
        self.pos = pos
class Solution:

    # Function to find the maximum number of meetings that can
    # be performed in a meeting room.
    def maximumMeetings(self, n, start, end):
        meet= []
        for i in range(n):
            meet.append(meeting(start[i], end[i], i))
        meet = sorted(meet, key = lambda mee: mee.end)
        limit = meet[0].end
        counter = 1
        for i in range(1, n):
            if meet[i].start > limit:
                counter += 1
                limit = meet[i].end
        return counter
