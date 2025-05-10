def solve(n, nums):
    return f"Sum: {sum(nums)}"

if __name__ == "__main__":
    try:
        # Read input from 'input.txt'
        with open('input.txt', 'r', encoding='utf-8') as infile:
            input_data = infile.read()

        # Process the input data
        nums = input_data.strip().split('\n')
        nums = list(map(lambda num: int(num), nums))
        n = nums[0]
        nums = nums[1:]
        output_data = solve(n, nums)

        # Write output to 'output.txt'
        with open('output.txt', 'w', encoding='utf-8') as outfile:
            outfile.write(output_data)

    except FileNotFoundError:
        print("Error: 'input.txt' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")
