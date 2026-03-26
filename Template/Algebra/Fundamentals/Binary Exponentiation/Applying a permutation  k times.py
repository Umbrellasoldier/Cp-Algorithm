def applyPermutation(sequence,permutation):
	newSequence=[]
	for i in range(len(sequence)):
		newSequence.append(sequence[permutation[i]])
	return newSequence

def permute_k_times(sequence,permutation,k):
	while k:
		if k&1:
			sequence=applyPermutation(sequence,permutation)
		permutation=applyPermutation(permutation,permutation)
		k>>=1
	return sequence