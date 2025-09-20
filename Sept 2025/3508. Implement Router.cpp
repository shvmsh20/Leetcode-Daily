#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int src, dst, t;
    bool operator==(const Packet& other) const {
        return src == other.src && dst == other.dst && t == other.t;
    }
};

struct PacketHash {
    size_t operator()(const Packet& p) const {
        return ((size_t)p.src * 1000003 + p.dst) * 1000003 + p.t;
    }
};

class Router {
public:
    Router(int memoryLimit) : limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (seen.count(p)) return false;

        if ((int)q.size() == limit) forwardOne();

        q.push_back(p);
        seen.insert(p);
        dstTimes[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet p = q.front();
        q.pop_front();
        seen.erase(p);
        removedCount[p.dst]++;
        return {p.src, p.dst, p.t};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!dstTimes.count(destination)) return 0;
        auto& times = dstTimes[destination];
        int startIdx = removedCount[destination];

        auto lo = lower_bound(times.begin() + startIdx, times.end(), startTime);
        auto hi = upper_bound(times.begin() + startIdx, times.end(), endTime);
        return hi - lo;
    }

private:
    int limit;
    deque<Packet> q;
    unordered_set<Packet, PacketHash> seen;
    unordered_map<int, vector<int>> dstTimes;
    unordered_map<int, int> removedCount;

    void forwardOne() {
        Packet p = q.front();
        q.pop_front();
        seen.erase(p);
        removedCount[p.dst]++;
    }
};
