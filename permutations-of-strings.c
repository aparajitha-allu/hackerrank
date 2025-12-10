#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0)
        i--;
    if (i < 0)
        return 0; // No more permutations

    // Step 2: Find largest index j > i such that s[j] > s[i]
    int j = n - 1;
    while (strcmp(s[j], s[i]) <= 0)
        j--;

    // Step 3: Swap s[i] and s[j]
    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    // Step 4: Reverse s[i+1] to s[n-1]
    int left = i + 1, right = n - 1;
    while (left < right)
    {
        char *tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }

    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}