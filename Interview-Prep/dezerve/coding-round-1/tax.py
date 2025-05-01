# tax slab
tax_slab_map = {
    "new": {
        "lower_limit_tax_rate": [
            {0: 0}, 
            {3: 5}, 
            {7: 10}, 
            {10: 15}, 
            {12: 20}, 
            {15: 30}
        ],
        "cess_rate": 4,
        "std_ded": 75000
    },
    "old": {
        "lower_limit_tax_rate": [
            {0: 0}, 
            {3: 5}, 
            {7: 10}, 
            {10: 15}, 
            {12: 20}, 
            {15: 30}
        ],
        "cess_rate": 4,
        "std_ded": 75000
    }
}
    
# 
# 
def search_lower_limit(nums, key):
    low = 0
    high = len(nums) - 1
    while low <= high:
        mid = low + (high-low)//2
        if nums[mid] <= key:
            low = mid
            if high == low:
                break
        else:
            high = mid - 1
    return nums[low]

def get_salary(tax, regime):
    slabs = tax_slab_map[regime.lower()]
    tax -= tax*slabs["cess_rate"]
    lower_limit, lower_tax = search_lower_limit(total_tax_constants[regime.lower()].values(), tax)
    lower_limit_rate = slabs["lower_limit_tax_rate"][lower_limit]
    salary = total_tax_constants[regime.lower()][lower_limit]
    salary +=  ((tax-lower_tax)*100)/lower_limit_rate
    salary += slabs["std_ded"]
    return salary


def calculate_tax(salary, regime):
    tax = 0
    slabs = tax_slab_map[regime.lower()]
    salary -= slabs["std_ded"]
    lower_limits = slabs["lower_limit_tax_rate"].keys()
    lower_limit = search_lower_limit(lower_limits, salary)
    lower_limit_rate = slabs["lower_limit_tax_rate"][lower_limit]
    tax += ((salary - lower_limit) * lower_limit_rate/100)
    tax += total_tax_constants[lower_limit]
    tax += tax*slabs["cess_rate"]
    return tax




def solve():
    salary = input("Enter salary")
    new_regime_tax = calculate_tax(salary, "NEW")
    expected_old_salary = get_salary(new_regime_tax, "OLD")
    minimum_deductions = abs(expected_old_salary - salary)
    print("Minimum deductions: ", minimum_deductions)

if __name__ == "__main__":
    total_tax_constants = {
        "old": {},
        "new": {}
    }
    regimes = ["old", "new"]
    for regime in regimes:
        slabs = tax_slab_map[regime.lower()]
        lower_limits = slabs["lower_limit_tax_rate"].keys()
        for index, lower_limit in enumerate(lower_limits):
            total_tax_constants[regime.lower()][lower_limit] = 
