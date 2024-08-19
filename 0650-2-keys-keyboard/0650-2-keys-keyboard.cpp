class Solution {
public:
    int cache[1001][1001];

    int minSteps(int on_screen, int on_clipboard, int n) {
        if (on_screen == n) {
            return 0;
        }

        int needed = n - on_screen;

        if (needed < on_clipboard) {
            return INT_MAX;
        }

        if (cache[on_screen][on_clipboard] != -1) {
            return cache[on_screen][on_clipboard];
        }
    
        int copy = INT_MAX;
        int paste = INT_MAX;

        if (needed > on_screen && on_screen != on_clipboard) {
            copy = minSteps(on_screen, on_screen, n);
        }

        paste = minSteps(on_screen + on_clipboard, on_clipboard, n);
    
        int min_step = min(copy, paste);

        return cache[on_screen][on_clipboard] = min_step + (min_step != INT_MAX ? 1 : 0);
    }

    int minSteps(int n) {
        memset(cache, -1, sizeof(cache));       
        return minSteps(1, 1, n) + (n == 1 ? 0 : 1);
    }
};