import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

ColorObject = np.uint8([[[50 ,38,212]]])
hsv_ColorObject = cv.cvtColor(ColorObject,cv.COLOR_BGR2HSV)
print(hsv_ColorObject)

# define range of blue color in HSV
lowerColorObject = np.array([hsv_ColorObject[0][0][0]-10, 100, 100])
upperColorObject = np.array([hsv_ColorObject[0][0][0]+10, 255, 255])


cap = cv.VideoCapture('videBal.mp4')

while(True):
    # Capture frame-by-frame
    ret, img = cap.read()

    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    # Threshold the HSV image to get only blue colors
    mask = cv.inRange(hsv, lowerColorObject, upperColorObject)

    kernel = np.ones((5, 5), np.uint8)
    mask2 = cv.erode(mask, kernel, iterations=1)

    # calculate moments of binary image
    M = cv.moments(mask2)

    # calculate x,y coordinate of center

    if M["m00"]!=0:
        cX = int(M["m10"] / M["m00"])
        cY = int(M["m01"] / M["m00"])

    res = cv.bitwise_and(img, img, mask=mask2)
    final = cv.circle(img, (cX, cY), 100, [255, 255, 255], thickness=10)

    # Display the resulting frame
    #cv.namedWindow('image', cv.WINDOW_NORMAL)
    #cv.namedWindow('mask', cv.WINDOW_NORMAL)
    #cv.namedWindow('res', cv.WINDOW_NORMAL)
    #cv.namedWindow('hsv', cv.WINDOW_NORMAL)
    cv.namedWindow('final', cv.WINDOW_NORMAL)

    #cv.imshow('hsv', hsv)
    #cv.imshow('image', img)
    #cv.imshow('mask', mask)
    #cv.imshow('res', res)
    cv.imshow('final', final)

    if cv.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv.destroyAllWindows()









