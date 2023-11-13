class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
        count = [0] * 10

        s_list = list(s)

        for i in range(len(s_list)):
            for j in range(10):
                if s_list[i] == vowels[j]:
                    count[j] += 1
                    s_list[i] = '*'
                    break

        j = 0
        while j < 10 and not count[j]:
            j += 1

        if j == 10:
            return ''.join(s_list)

        for i in range(len(s_list)):
            if s_list[i] == '*':
                s_list[i] = vowels[j]
                count[j] -= 1
                while j < 10 and not count[j]:
                    j += 1

                if j == 10:
                    return ''.join(s_list)

        return ''.join(s_list)