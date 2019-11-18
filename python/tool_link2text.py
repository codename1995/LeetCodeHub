
# transfer address/link from leetcode to demanding format
# @ Input
#       int-> Problem No : 230
#       str-> hyperlink : https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
# @ Return
# 1. Problem hyperlink (Markdown)
#   [Kth Smallest Element In A Bst](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)
# 2. Project hyperlink (Markdown)
#   [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/230_Kth_Smallest_Element_In_A_Bst/Kth_Smallest_Element_In_A_Bst.cpp)
#   [Python](https://github.com/codename1995/LeetCodeHub/blob/master/python/230.LargestNumber.py) ####
# 3. VS Project Name
#   230_Kth_Smallest_Element_In_A_Bst
#

idx = eval(input("Please input the No. of problem:"))
hyperlink = input("Please input the hyperlink:")
# idx = 230
# hyperlink = "https://leetcode-cn.com/problems/single-number-iii/"
Problem_name = hyperlink.split('/')[4]

# Parameters
prefilix_cpp_project = "https://github.com/codename1995/leetcodehub/blob/master/cpp/"
prefilix_python_file = "https://github.com/codename1995/leetcodehub/blob/master/python/"

# 1 Problem hyperlink
titled_hyperlink_with_space = Problem_name.replace('-', ' ').title()
last_word = titled_hyperlink_with_space.split(' ')[-1]
b_last_word_is_index = True
for ch in last_word:
    if ch not in {'i', 'I', 'v', 'V'}:
        b_last_word_is_index = False
        break
if b_last_word_is_index:
     titled_hyperlink_with_space = titled_hyperlink_with_space[:-len(last_word)] + titled_hyperlink_with_space[-len(last_word):].upper()

# a = titled_hyperlink_with_space[-len(last_word):]
# print("%d [%s](%s)"%(idx, titled_hyperlink_with_space, hyperlink))

# 3 VS Project Name
hyperlink_with_underling = titled_hyperlink_with_space.replace(' ', '_')
project_name = str(idx) + '_' + hyperlink_with_underling

# 2 C++ & Python Linkk
pure_project_name = project_name[project_name.find('_')+1:]
# hyperlink_cpp = prefilix_cpp_project + project_name + '/' + pure_project_name + '.cpp'
hyperlink_cpp = prefilix_cpp_project + project_name + '/' + project_name + '.cpp'
hyperlink_python = prefilix_python_file + project_name + '.py'
# print("%s"%(project_name))

# Output
print("%d [%s](%s) | [C++](%s) |\n"%(idx, titled_hyperlink_with_space, hyperlink, hyperlink_cpp))

# combine C++ and python link is too long for one line, so put python link in a additional line
# print("%d [%s](%s) | [C++](%s), [Python](%s) |"\
#       %(idx, titled_hyperlink_with_space, hyperlink, hyperlink_cpp, hyperlink_python))
print(", [Python](%s)\n"%(hyperlink_python))


print(project_name)
