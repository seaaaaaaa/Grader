#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>> temp;
    while(!a.empty()){
        std::vector<std::queue<int>> vec = a.top(); 
        for(auto &q : vec){
            std::queue<int> new_q;
            while(!q.empty()){
                int val = q.front();
                q.pop();
                if(val == from){
                    val = to;
                }
                new_q.push(val);
            }
            q = new_q;
        }
        temp.push(vec);
        a.pop();
    }
    while(!temp.empty()){
        a.push(temp.top());
        temp.pop();
    }
    
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto &entry : a){
        std::priority_queue<int> new_pq;
        while(!entry.second.first.empty()){
            int val = entry.second.first.top();
            entry.second.first.pop();
            if(val == from){
                val = to;
            }
            new_pq.push(val);
        }
        if (entry.second.second == from){
            entry.second.second = to;
        }
        entry.second.first = new_pq;
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> new_set;
    for(auto &entry : a){
        std::list<int> new_list;
        for(auto val : entry.first){
            if(val == from){
                val = to;
                
            }
            new_list.push_back(val);
            
        }
        std::map<int, std::pair<int, string>> new_map;
        for(auto &m_entry : entry.second){
            int key = m_entry.first;
            if(key == from){
                key = to;
            }
            int val1 = m_entry.second.first;
            if(val1 == from){
                val1 = to;
            }
            new_map[key] = std::make_pair(val1, m_entry.second.second);
        }
        new_set.insert(std::make_pair(new_list, new_map));
    }
    a = new_set;
}

#endif