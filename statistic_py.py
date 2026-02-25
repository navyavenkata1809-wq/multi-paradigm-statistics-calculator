class StatisticsCalculator:
    """Class for calculating basic statistics."""
    
    def __init__(self, data):
        self.data = data
    
    def calculate_mean(self):
        """Calculate mean (average)."""
        total = sum(self.data)
        count = len(self.data)
        return total / count
    
    def calculate_median(self):
        """Calculate median (middle value)."""
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        
        if n % 2 == 0:
            middle1 = sorted_data[n//2 - 1]
            middle2 = sorted_data[n//2]
            return (middle1 + middle2) / 2.0
        else:
            return sorted_data[n//2]
    
    def calculate_mode(self):
        """Calculate mode (most frequent value)."""
        # Count how many times each number appears
        frequency = {}
        for num in self.data:
            if num in frequency:
                frequency[num] = frequency[num] + 1
            else:
                frequency[num] = 1
        
        # Find the highest frequency
        max_count = 0
        for count in frequency.values():
            if count > max_count:
                max_count = count
        
        # Find all numbers with highest frequency
        modes = []
        for num, count in frequency.items():
            if count == max_count:
                modes.append(num)
        
        return sorted(modes), max_count
    
    def display_statistics(self):
        """Display all statistics."""
        print("Input Data:", self.data)
        print()
        
        mean = self.calculate_mean()
        print("Mean:", round(mean, 2))
        
        median = self.calculate_median()
        print("Median:", round(median, 2))
        
        modes, frequency = self.calculate_mode()
        print("Mode(s):", modes, "(appears", frequency, "time(s))")


# Main program

# Test case 1
data1 = [15, 23, 15, 42, 18, 23, 15, 30, 25, 18]
calc1 = StatisticsCalculator(data1)
calc1.display_statistics()
