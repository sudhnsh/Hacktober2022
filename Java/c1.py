class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hist_str_dict = {}

        for string in strs:
            temp = "".join(sorted(string))
            if temp in hist_str_dict:
                hist_str_dict[temp].append(string)
            else:
                hist_str_dict[temp] = [string]
        return hist_str_dict.values()
