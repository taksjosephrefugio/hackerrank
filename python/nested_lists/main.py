list_of_dict = []
scores = []

for _ in range(int(input())):
	name = input()
	score = float(input())
	scores.append(score)

	temp_dict = { score: name }
	list_of_dict.append(temp_dict)

scores.remove(min(scores))
second_min = min(scores)
print(second_min)

# FIXME: remove list_of_dict item if it contains second_min