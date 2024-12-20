#include <bits/stdc++.h>

using namespace std;
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
typedef long long ll;
typedef pair<int, int> pii;

int N, A, B;
pii villagers[200005]; 


multiset<int> getTopDecorators(int A, int B) {
    vector<int> decorators;
    for (int i = A; i < N; i++) {
        decorators.push_back(villagers[i].second); // Collect decoration skills
    }
    sort(decorators.rbegin(), decorators.rend()); // Sort in descending order
    
    multiset<int> topBDecorators;
    for (int i = 0; i < B; i++) {
        topBDecorators.insert(decorators[i]); // Select top B decorators
    }
    return topBDecorators;
}

int main() {
    fastIO;
    cin >> A >> B >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        villagers[i] = {x, y}; 
    }

    
    sort(villagers, villagers + N, [](pii a, pii b) {
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    });

    // Calculate initial rowing skill sum for top A rowers
    ll rowingSkillSum = 0;
    priority_queue<int> rowerDiffs; // Store the difference between decoration and rowing skill
    for (int i = 0; i < A; i++) {
        rowingSkillSum += villagers[i].first; // Sum rowing skills of top A rowers
        rowerDiffs.push(villagers[i].second - villagers[i].first); // Track differences
    }

    // Get the initial top B decorators
    multiset<int> decorators = getTopDecorators(A, B);
    ll decorationSkillSum = accumulate(decorators.begin(), decorators.end(), 0LL); // Sum of top B decoration skills

    ll maxTotalSkill = rowingSkillSum + decorationSkillSum;

    // Try updating rowers and decorators to find the maximum possible skill sum
    for (int i = A; i < A + B; i++) {
        // Add current villager's rowing skill to rower sum
        rowingSkillSum += villagers[i].first;

        // Adjust for the best rower difference
        rowerDiffs.push(villagers[i].second - villagers[i].first);
        rowingSkillSum += rowerDiffs.top(); // Add max diff
        rowerDiffs.pop();

        // Adjust the decorator skill sum
        auto worstDecorator = decorators.lower_bound(villagers[i].second);
        cerr << *worstDecorator << '\n';
        decorationSkillSum -= *worstDecorator; // Remove smallest decorator skill
        decorators.erase(worstDecorator);

        maxTotalSkill = max(maxTotalSkill, rowingSkillSum + decorationSkillSum);
    }

    cout << maxTotalSkill << endl; // Output the maximum skill sum
    return 0;
}
