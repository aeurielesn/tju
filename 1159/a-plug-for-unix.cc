#include <vector>
#include <list>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define PB push_back
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

#define GETNUM(n) { \
  n=0; \
  while (*start>32) { \
    n<<=1; n*=5; n+=*start-'0'; \
    start++; \
  } \
}

using namespace std;

typedef pair<string,int> key;

const int MAX_NODES = 402;
const int INF = 0x3F3F3F3F;

int adj[MAX_NODES][MAX_NODES], sz[MAX_NODES];
int cap[MAX_NODES][MAX_NODES];
int prevnode[MAX_NODES], flow[MAX_NODES];
int N;

// Priority-First Search
int PFS(int s, int t) {
  FOR(i, N) prevnode[i]=-1, flow[i]=0;
  deque<int> Q;
  Q.PB(s);
  flow[s]=INF;

  while(!Q.empty()) {
    int node=Q.front();
    Q.pop_front();

    if(node==t) break;

    for(int i=0; i<sz[node]; ++i) {
      int next=adj[node][i];
      if(flow[next] || cap[node][next]==0) continue;
      flow[next]=min(flow[node], cap[node][next]);
      prevnode[next]=node;
      Q.PB(next);
    }
  }

  int fl=flow[t];
  while(prevnode[t]!=-1) {
    cap[t][prevnode[t]]+=fl;
    cap[prevnode[t]][t]-=fl;
    t=prevnode[t];
  }

  return fl;
}

// Maximum Flow
int MaximumFlow(int s, int t) {
  int flow=0;
  int pathcap=0;
  do {
    pathcap = PFS(s, t);
    flow += pathcap;
  } while(pathcap);
  return flow;
}

int main()
{
    char str1[100];
    int cases, n, m, t, u, k;
    int source=0, sink=1;
    char receptaclesInput[101][100];
    char devicesInput[101][100];
    char adaptersInput[101][2][100];
    int mapReceptacles[101];
    int mapDevices[101];
    int mapAdapters[101][2];
    char output[1000];
    char *start;

    memset(mapReceptacles,0,sizeof(mapReceptacles));
    memset(mapDevices,0,sizeof(mapDevices));
    memset(mapAdapters,0,sizeof(mapAdapters));
    memset(sz,0,sizeof(sz));

    memset(cap,0,sizeof(cap));

    N = 2;

    // receptacles
    start = gets(str1);
    GETNUM(n);
    FOR(i,n) gets(receptaclesInput[i]);

    // devices
    start = gets(str1);
    GETNUM(m);
    FOR(i,m) gets(str1), sscanf(str1,"%*s %s",&devicesInput[i]);

    // adapters
    start = gets(str1);
    GETNUM(k);
    FOR(i,k) gets(str1), sscanf(str1,"%s %s",&adaptersInput[i][0],&adaptersInput[i][1]);

    FOR(i,n)
    {
        if(!mapReceptacles[i])
        {
            mapReceptacles[i] = N++;
            FORI(j,i+1,n) if(!mapReceptacles[j] && strcmp(receptaclesInput[i],receptaclesInput[j])==0) mapReceptacles[j]=mapReceptacles[i];
            FOR(j,m) if(!mapDevices[j] && strcmp(receptaclesInput[i],devicesInput[j])==0) mapDevices[j]=mapReceptacles[i];
            FOR(j,k)
            {
                if(!mapAdapters[j][0] && strcmp(receptaclesInput[i],adaptersInput[j][0])==0) mapAdapters[j][0]=mapReceptacles[i];
                if(!mapAdapters[j][1] && strcmp(receptaclesInput[i],adaptersInput[j][1])==0) mapAdapters[j][1]=mapReceptacles[i];
            }
        }
    }
    FOR(i,m)
    {
        if(!mapDevices[i])
        {
            mapDevices[i] = N++;
            FORI(j,i+1,m) if(!mapDevices[j] && strcmp(devicesInput[i],devicesInput[j])==0) mapDevices[j]=mapDevices[i];
            FOR(j,k)
            {
                if(!mapAdapters[j][0] && strcmp(devicesInput[i],adaptersInput[j][0])==0) mapAdapters[j][0]=mapDevices[i];
                if(!mapAdapters[j][1] && strcmp(devicesInput[i],adaptersInput[j][1])==0) mapAdapters[j][1]=mapDevices[i];
            }
        }
    }
    FOR(i,k)
    {
        if(!mapAdapters[i][0])
        {
            mapAdapters[i][0] = N++;
            FORI(j,i+1,k)
            {
                if(!mapAdapters[j][0] && strcmp(adaptersInput[i][0],adaptersInput[j][0])==0) mapAdapters[j][0]=mapAdapters[i][0];
                if(!mapAdapters[j][1] && strcmp(adaptersInput[i][0],adaptersInput[j][1])==0) mapAdapters[j][1]=mapAdapters[i][0];
            }
        }
        if(!mapAdapters[i][1])
        {
            mapAdapters[i][1] = N++;
            FORI(j,i+1,k)
            {
                if(!mapAdapters[j][0] && strcmp(adaptersInput[i][1],adaptersInput[j][0])==0) mapAdapters[j][0]=mapAdapters[i][1];
                if(!mapAdapters[j][1] && strcmp(adaptersInput[i][1],adaptersInput[j][1])==0) mapAdapters[j][1]=mapAdapters[i][1];
            }
        }
    }

    FOR(i,n)
    {
        t = mapReceptacles[i];
        if(!cap[source][t]) adj[source][sz[source]++]=t, adj[t][sz[t]++]=source;
        cap[source][t]++;
    }

    FOR(i,m)
    {
        t = mapDevices[i];
        if(!cap[t][sink]) adj[t][sz[t]++]=sink, adj[sink][sz[sink]++]=t;
        cap[t][sink]++;
    }

    FOR(i,k)
    {
        t = mapAdapters[i][0], u = mapAdapters[i][1];
        if((!cap[u][t]) && (!cap[t][u])) adj[u][sz[u]++]=t, adj[t][sz[t]++]=u;
        cap[u][t]=INF;
    }

    int useds = MaximumFlow(source,sink);

    printf("%d\n",m-useds);

    return 0;
}
