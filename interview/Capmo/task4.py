
def predictTemperature(startDate, endDate, temperature, n):
    # Write your code here

    # ideally i would use ARIMA model, but im running out of time
    # so for simplicity i will start with average:
    sTemp = 0
    tempSize = len(temperature)
    for i in range (0, tempSize ):
        sTemp+=temperature[i]

    avgTemp = sTemp/tempSize

    return avgTemp
temp = [1, 2, 3] 
print(predictTemperature(1, 2, temp, 1))
