class Pair {
    int sr;
    int idx;

    Pair(int sr, int idx) {
        this.sr = sr;
        this.idx = idx;
    }
}

class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {

        int n = servers.length;
        int m = tasks.length;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            if (a.sr != b.sr) {
                return Integer.compare(a.sr, b.sr);
            }
            return Integer.compare(a.idx, b.idx);
        });

        TreeMap<Long, List<Pair>> mp = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            pq.offer(new Pair(servers[i], i));
        }

        int[] ans = new int[m];

        int t = 0;
        long time = 0;

        while (t < m) {

            time = Math.max(time, t);

            while (!mp.isEmpty() && mp.firstKey() <= time) {
                long freeTime = mp.firstKey();

                List<Pair> list = mp.remove(freeTime);

                for (Pair p : list) {
                    pq.offer(p);
                }
            }

            if (pq.isEmpty()) {
                time = mp.firstKey();
                continue;
            }

            Pair p = pq.poll();

            ans[t] = p.idx;

            long freeTime = time + tasks[t];

            mp.computeIfAbsent(freeTime, k -> new ArrayList<>()).add(p);

            t++;
        }

        return ans;
    }
}