class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int alwaysHappy = 0;
        int n = grumpy.size();
        
        // Sum of customers at times when the seller is not grumpy
        for (int i = 0; i < n; i++) {
            if (!grumpy[i]) alwaysHappy += customers[i];
        }

        // Calculate the increasedByTrick for the initial window
        int increasedByTrick = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i]) increasedByTrick += customers[i];
        }

        int incMax = increasedByTrick;

        // Slide the window and update incMax
        for (int i = 0; i < n - minutes; i++) {
            if (grumpy[i]) increasedByTrick -= customers[i]; // Remove effect of outgoing element
            if (grumpy[i + minutes]) increasedByTrick += customers[i + minutes]; // Add effect of incoming element
            incMax = max(increasedByTrick, incMax);
        }

        // Return the total number of satisfied customers
        return incMax + alwaysHappy;
    }
};
