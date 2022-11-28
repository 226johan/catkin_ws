;; Auto-generated. Do not edit!


(when (boundp 'learning_message::Person)
  (if (not (find-package "LEARNING_MESSAGE"))
    (make-package "LEARNING_MESSAGE"))
  (shadow 'Person (find-package "LEARNING_MESSAGE")))
(unless (find-package "LEARNING_MESSAGE::PERSON")
  (make-package "LEARNING_MESSAGE::PERSON"))

(in-package "ROS")
;;//! \htmlinclude Person.msg.html


(defclass learning_message::Person
  :super ros::object
  :slots (_name _age _height ))

(defmethod learning_message::Person
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:height __height) 0.0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _height (float __height))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; int32 _age
    4
    ;; float64 _height
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; int32 _age
       (write-long _age s)
     ;; float64 _height
       (sys::poke _height (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _age
     (setq _age (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _height
     (setq _height (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get learning_message::Person :md5sum-) "89500ecfac5e4bf01d7c73634349e7a4")
(setf (get learning_message::Person :datatype-) "learning_message/Person")
(setf (get learning_message::Person :definition-)
      "string    name
int32     age
float64   height
")



(provide :learning_message/Person "89500ecfac5e4bf01d7c73634349e7a4")


