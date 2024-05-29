from playsound import playsound
import cv2
import serial
import time
from  audio import play
import threading
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(1)
ArduinoSerial = serial.Serial('com5', 9600, timeout=0.1)  #uncomment this when you are in  hackathon 
time.sleep(1)
a = 98
while cap.isOpened():
    ret, frame = cap.read() # Rename the variable 'playsound' to something else
    frame = cv2.flip(frame, 1)  # mirror the image
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))
    for x, y, w, h in faces:
      
        a+=1                  #uncomment this when you are in  hackathon
        if(len(faces)>0 and a==100):
            # t1 = threading.Thread(target=play)
            # t1.run()
            a = 0
        string = 'X{0:d}Y{1:d}'.format((x + w // 2), (y + h // 2))
        print(string)
      
        cv2.circle(frame, (x + w // 2, y + h // 2), 2, (0, 255, 0), 2)
       
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 3)
  
    cv2.rectangle(frame, (640 // 2 - 30, 480 // 2 - 30),
                  (640 // 2 + 30, 480 // 2 + 30),
                  (255, 255, 255), 3)
    cv2.imshow('img', frame)
    if cv2.waitKey(10) & 0xFF == ord('q'):  # press q to Quit
        break

cap.release()
# ArduinoSerial.close() #uncomment this when you are in  hackathon
cv2.destroyAllWindows()
