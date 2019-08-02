# Dont use any string deconstructor methods! Those run in O(n) e.g. Splicing


def naive_pattern_match(a_str):
    match_list = [0]
    # Does explicit_matching for each substring within the string
    for i in range(1, len(a_str)):
        # i denotes the index of the beginning of each substring
        match_list.append(explicit_match(a_str, i))
        return match_list


def explicit_match(a_str, sub_str_index, str_index=0):
    # Does explicit matching of sub_string and vanilla string
    # sub_string_index: The index where the substring begins
    # str_index: Index of where we should start matching the normal string
    # Returns the length of how many matched characters. (e.g. 0 means no matched characters)
    a_str_index = str_index
    for i in range(sub_str_index, len(a_str)):
        if a_str[a_str_index] != a_str[i]:
            return a_str_index
        a_str_index += 1
    return a_str_index - str_index
    # You need to substract as this function returns the length


def z_alg(a_str):
    z_k_list = [0]
    # Do explicit pattern matching for z1 to establish r and l
    z1 = explicit_match(a_str, 1)
    z_k_list.append(z1)
    if z1 == 0:
        r = 0
        l = 0
    else:
        r = z1
        l = 1
    # Loop to preprocess the string, since z1 is processed, start at index 2
    for k in range(2, len(a_str)):
        if k > r:
            # Case 1
            z_k = explicit_match(a_str, k)
            z_k_list.append(z_k)
            if z_k > 0:
                r = z_k + k - 1
                l = k
        else:
            # Case 2
            k_prime = k - l
            suffix_length = r - k   # The length from k to r
            if z_k_list[k_prime] < suffix_length + 1:
                # Case 2a: No need to do explicit matching
                # z_k is the same as z_k_prime. r and l remains unchanged
                z_k_list.append(z_k_list[k_prime])
            else:
                # Case 2b: Need to do explicit matching
                extra_length = explicit_match(a_str, r + 1, r - k + 1)
                r = r + extra_length    # Update r to add the additional length
                # This r refers to the updated r from the line above
                z_k_list.append(r - k + 1)  # Inclusive of k itself, so +1
                l = k   # Update the l to be the current k
    return z_k_list


if __name__ == "__main__":
    sample_string = "aabaabcaxaabaabcy"
    sample_string_2 = "abxyabxz$xabxyabxyabxz"
    # naive_list = naive_pattern_match(sample_string_2)
    # print(naive_list)
    # z_alg(sample_string)
    processed_list = z_alg(sample_string_2)
    # processed_list = z_alg(sample_string)
    print(processed_list)
