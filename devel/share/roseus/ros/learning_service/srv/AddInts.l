;; Auto-generated. Do not edit!


(when (boundp 'learning_service::AddInts)
  (if (not (find-package "LEARNING_SERVICE"))
    (make-package "LEARNING_SERVICE"))
  (shadow 'AddInts (find-package "LEARNING_SERVICE")))
(unless (find-package "LEARNING_SERVICE::ADDINTS")
  (make-package "LEARNING_SERVICE::ADDINTS"))
(unless (find-package "LEARNING_SERVICE::ADDINTSREQUEST")
  (make-package "LEARNING_SERVICE::ADDINTSREQUEST"))
(unless (find-package "LEARNING_SERVICE::ADDINTSRESPONSE")
  (make-package "LEARNING_SERVICE::ADDINTSRESPONSE"))

(in-package "ROS")





(defclass learning_service::AddIntsRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod learning_service::AddIntsRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass learning_service::AddIntsResponse
  :super ros::object
  :slots (_sum ))

(defmethod learning_service::AddIntsResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass learning_service::AddInts
  :super ros::object
  :slots ())

(setf (get learning_service::AddInts :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get learning_service::AddInts :datatype-) "learning_service/AddInts")
(setf (get learning_service::AddInts :request) learning_service::AddIntsRequest)
(setf (get learning_service::AddInts :response) learning_service::AddIntsResponse)

(defmethod learning_service::AddIntsRequest
  (:response () (instance learning_service::AddIntsResponse :init)))

(setf (get learning_service::AddIntsRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get learning_service::AddIntsRequest :datatype-) "learning_service/AddIntsRequest")
(setf (get learning_service::AddIntsRequest :definition-)
      "int32 num1
int32 num2
---
int32 sum
")

(setf (get learning_service::AddIntsResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get learning_service::AddIntsResponse :datatype-) "learning_service/AddIntsResponse")
(setf (get learning_service::AddIntsResponse :definition-)
      "int32 num1
int32 num2
---
int32 sum
")



(provide :learning_service/AddInts "4781436a0c2affec8025955a6041e481")


