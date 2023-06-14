"""
Coin recognition, real life application
task: calculate the value of coins on picture
"""
#https://wyattsmcall1.github.io/documents/FinalReportECE420.pdf
# Parameter entnommen aus Wikipedia
# kupfer	1	16,25		1
# kupfer	2	18,75		1,153846154
# kupfer	5	21,25		1,307692308
# gold	10	19,75		1,215384615
# gold	20	22,25		1,369230769
# gold	50	24,25		1,492307692
# zwei farben	1	23,25		1,430769231
# zwei farben	2	25,75		1,584615385


import cv2
import numpy as np

imagename = 'coins.jpg'

def detect_coins():
    coins = cv2.imread(imagename, 1)

    gray = cv2.cvtColor(coins, cv2.COLOR_BGR2GRAY)
    cv2.imshow('grayscaled image', gray)
    img = cv2.medianBlur(gray, 7)
    cv2.imshow('medianBlur image', img)
    circles = cv2.HoughCircles(
        img,  # input image
        cv2.HOUGH_GRADIENT,  # type of detection
        dp=1, #inverse ratio of resolution
        minDist = 50, #minimum distance between detected circled
        param1=145, #internal threshold for internal canny edge detector
        param2=50, #threshold for center detection
        minRadius=10,  # mininmum radius to be detected. if unknown, put zero as default
        maxRadius=380,  # max radius to be detected. if unknown, put zero as default
    )

    coins_copy = coins.copy()


    for detected_circle in circles[0]:
        x_coor, y_coor, detected_radius = detected_circle
        coins_detected = cv2.circle(
            coins_copy,
            (int(x_coor), int(y_coor)),
            int(detected_radius),
            (0, 255, 0),
            4,
        )
    print(circles)
    cv2.imwrite("./test_Hough.jpg", coins_detected)
    cv2.imshow('coins detected', coins_detected)
    return circles

def calculate_amount(): #die ratio ist der Quotient bezogen auf den durchmesser 1 cent
    eurparam = {
        "1 cent": {
            "value": 0.01,
            "radius": 16.25,
            "ratio": 16.25/16.25,
            "count": 0,
        },
        "2 cent": {
            "value": 0.02,
            "radius": 18.75,
            "ratio": 18.75/16.25,
            "count": 0,
        },
        "5 cent": {
            "value": 0.05,
            "radius": 21.25,
            "ratio": 21.25/16.25,
            "count": 0,
        },
        "10 cent": {
            "value": 0.10,
            "radius": 19.75,
            "ratio": 19.75/16.25,
            "count": 0,
        },
        "20 cent": {
            "value": 0.20,
            "radius": 22.25,
            "ratio": 22.25/16.25,
            "count": 0,
        },
        "50 cent": {
            "value": 0.50,
            "radius": 24.25,
            "ratio": 24.25/16.25,
            "count": 0,
        },
        "1 Euro": {
            "value": 1,
            "radius": 23.25,
            "ratio": 23.25/16.25,
            "count": 0,
        },
        "2 Euro": {
            "value": 2,
            "radius": 25.5,
            "ratio": 25.5/16.25,
            "count": 0,
        },
    }

    circles = detect_coins()
    radius = []
    coordinates = []

    for detected_circle in circles[0]:
        x_coor, y_coor, detected_radius = detected_circle
        radius.append(detected_radius)
        coordinates.append([x_coor, y_coor])

    smallest = min(radius)
    tolerance = 0.03
    total_amount = 0

    coins_circled = cv2.imread('./test_Hough.jpg', 1)
    font = cv2.FONT_HERSHEY_SIMPLEX
    for coin in circles[0]:
        ratio_to_check = coin[2] / smallest #calculate real ratio
        coor_x = coin[0]
        coor_y = coin[1]
        
        for i in eurparam:
            value = eurparam[i]['value']
            ratio = eurparam[i]['ratio']
            #if value == 1:
            #    print(abs(ratio_to_check - eurparam[i]['ratio']))
            #    print(eurparam[i]['value'])
            #check if absolute between ideal and real ratio
            if abs(ratio_to_check - ratio) <= tolerance:
                print(abs(ratio_to_check - ratio))
                print(value)
                eurparam[i]['count'] += 1 #Zugriff auf Variable
                total_amount += value
                cv2.putText(coins_circled, str(value), (int(coor_x), int(coor_y)), font, 1,
                            (0, 0, 255), 4)

    print(f"The total amount is {total_amount} Euro")
    for i in eurparam:
        pieces = eurparam[i]['count']
        print(f"{i} = {pieces}x")


    cv2.imwrite("./test_Hough.jpg", coins_circled)
    cv2.imshow('coins_value', coins_circled)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    calculate_amount()