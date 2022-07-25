using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Newtonsoft.Json.Linq;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
?
// Namespace of "CapsuleHand" script
using Leap.Unity;
?
// In order to use "Hand"
using Leap;
?
public class RecordHandInfo : MonoBehaviour
{
    string GesturePath = @"C:\Users\HCITECH_03\Desktop\rachel\LeapMotion\5_UltraleapDevelopersDoc\Assets\Gestures";
    // To have reference to other scripts,
    // Define them in advance
    CapsuleHand capsuleHand;
    ?
        Hand hand;
    ?
        GameObject gestureObject;
    JsonHand gestureHand;
    Gesture storedGesture = new Gesture();
    JObject jsonGesture;
    ?
        // When you use other scripts, 
        // usually assign the script through Awake()
        private void Awake()
    {
        capsuleHand = gameObject.GetComponent<CapsuleHand>();
        gestureObject = GameObject.Find("RightHandGesture");
        gestureHand = gestureObject.GetComponent<JsonHand>();
    }
    ?

        void Start()
    {
        // Get One Hand
        hand = capsuleHand.GetLeapHand();
        ?
    }
    ?
        ?
        public JsonFinger leapFingerToJsonFinger(Finger.FingerType fingerType, Bone[] fingerBones, float fingerLength, float fingerWidth)
    {
        JsonFinger currentFinger = new JsonFinger();
        ?
            currentFinger.fingerType = fingerType;
        currentFinger.length = fingerLength;
        currentFinger.width = fingerWidth;
        ?
            foreach(Bone bone in fingerBones)
        {
            JsonBone currentBone = new JsonBone();
            currentBone.boneType = bone.Type;
            currentBone.length = bone.Length;
            currentBone.width = bone.Width;
            currentBone.centerPosition = bone.Center.ToVector3();
            currentBone.rotation = bone.Rotation.ToQuaternion();
            ?
                ?
                switch (bone.Type)
                {
                case Bone.BoneType.TYPE_METACARPAL:
                    currentFinger.metacarpalBone = currentBone;
                    break;
                    ?
                case Bone.BoneType.TYPE_PROXIMAL:
                    currentFinger.proximalBone = currentBone;
                    break;
                    ?
                case Bone.BoneType.TYPE_INTERMEDIATE:
                    currentFinger.intermediateBone = currentBone;
                    break;
                    ?
                case Bone.BoneType.TYPE_DISTAL:
                    currentFinger.distalBone = currentBone;
                    break;
                    ?
                default:
                    UnityEngine.Debug.Log("Invalid Bone");
                    break;
                }
        }
        return currentFinger;
    }
    ?
        public ObjFinger leapFingerToObjFinger(Finger.FingerType fingerType, Bone[] fingerBones, float fingerLength, float fingerWidth)
    {
        ObjFinger currentFinger = new ObjFinger();
        ?
            currentFinger.fingerType = fingerType;
        currentFinger.length = fingerLength;
        currentFinger.width = fingerWidth;
        ?
            foreach(Bone bone in fingerBones)
        {
            ObjBone currentBone = new ObjBone();
            currentBone.boneType = bone.Type;
            currentBone.length = bone.Length;
            currentBone.width = bone.Width;
            currentBone.centerPosition = bone.Center.ToVector3();
            currentBone.rotation = bone.Rotation.ToQuaternion();
            ?
                ?
                switch (bone.Type)
                {
                case Bone.BoneType.TYPE_METACARPAL:
                    currentFinger.metacarpalBone = currentBone;
                    break;
                    ?
                case Bone.BoneType.TYPE_PROXIMAL:
                    currentFinger.proximalBone = currentBone;
                    break;
                    ?
                case Bone.BoneType.TYPE_INTERMEDIATE:
                    currentFinger.intermediateBone = currentBone;
                    break;
                    ?
                case Bone.BoneType.TYPE_DISTAL:
                    currentFinger.distalBone = currentBone;
                    break;
                    ?
                default:
                    UnityEngine.Debug.Log("Invalid Bone");
                    break;
                }
        }
        return currentFinger;
    }
    ?
        ?
        //public JsonVector3 Vector3ToJsonVector3(Vector3 vector)
        //{
        //    JsonVector3 jsonVector3 = new JsonVector3();
        //    jsonVector3.x = vector.x;
        //    jsonVector3.y = vector.y;
        //    jsonVector3.z = vector.z;
        ?
        //    return jsonVector3;
        //}
        ?
        public JsonHand leapHandToJsonHand(Hand hand)
    {
        JsonHand currentHand = new JsonHand();
        ?
            currentHand.isLeft = hand.IsLeft;
        currentHand.palmPosition = hand.GetPalmPose().position;
        currentHand.palmRotation = hand.GetPalmPose().rotation;
        ?
            Finger thumb = hand.GetThumb();
        Bone[] thumbBones = thumb.bones;
        float thumbLength = thumb.Length;
        float thumbWidth = thumb.Width;
        Finger.FingerType thumbType = thumb.Type;
        ?
            Finger index = hand.GetIndex();
        Bone[] indexBones = index.bones;
        float indexLength = index.Length;
        float indexWidth = index.Width;
        Finger.FingerType indexType = index.Type;
        ?
            Finger middle = hand.GetMiddle();
        Bone[] middleBones = middle.bones;
        float middleLength = middle.Length;
        float middleWidth = middle.Width;
        Finger.FingerType middleType = middle.Type;
        ?
            Finger ring = hand.GetRing();
        Bone[] ringBones = ring.bones;
        float ringLength = ring.Length;
        float ringWidth = ring.Width;
        Finger.FingerType ringType = ring.Type;
        ?
            Finger pinky = hand.GetPinky();
        Bone[] pinkyBones = pinky.bones;
        float pinkyLength = pinky.Length;
        float pinkyWidth = pinky.Width;
        Finger.FingerType pinkyType = pinky.Type;
        ?
            currentHand.thumbFinger = leapFingerToJsonFinger(thumbType, thumbBones, thumbLength, thumbWidth);
        currentHand.indexFinger = leapFingerToJsonFinger(indexType, indexBones, indexLength, indexWidth);
        currentHand.middleFinger = leapFingerToJsonFinger(middleType, middleBones, middleLength, middleWidth);
        currentHand.ringFinger = leapFingerToJsonFinger(ringType, ringBones, ringLength, ringWidth);
        currentHand.pinkyFinger = leapFingerToJsonFinger(pinkyType, pinkyBones, pinkyLength, pinkyWidth);
        ?
            return currentHand;
    }

    public ObjHand leapHandToObjHand(Hand hand)
    {
        ObjHand currentHand = new ObjHand();
        ?
            currentHand.isLeft = hand.IsLeft;
        currentHand.palmPosition = hand.GetPalmPose().position;
        currentHand.palmRotation = hand.GetPalmPose().rotation;
        ?
            Finger thumb = hand.GetThumb();
        Bone[] thumbBones = thumb.bones;
        float thumbLength = thumb.Length;
        float thumbWidth = thumb.Width;
        Finger.FingerType thumbType = thumb.Type;
        ?
            Finger index = hand.GetIndex();
        Bone[] indexBones = index.bones;
        float indexLength = index.Length;
        float indexWidth = index.Width;
        Finger.FingerType indexType = index.Type;
        ?
            Finger middle = hand.GetMiddle();
        Bone[] middleBones = middle.bones;
        float middleLength = middle.Length;
        float middleWidth = middle.Width;
        Finger.FingerType middleType = middle.Type;
        ?
            Finger ring = hand.GetRing();
        Bone[] ringBones = ring.bones;
        float ringLength = ring.Length;
        float ringWidth = ring.Width;
        Finger.FingerType ringType = ring.Type;
        ?
            Finger pinky = hand.GetPinky();
        Bone[] pinkyBones = pinky.bones;
        float pinkyLength = pinky.Length;
        float pinkyWidth = pinky.Width;
        Finger.FingerType pinkyType = pinky.Type;
        ?
            currentHand.thumbFinger = leapFingerToObjFinger(thumbType, thumbBones, thumbLength, thumbWidth);
        currentHand.indexFinger = leapFingerToObjFinger(indexType, indexBones, indexLength, indexWidth);
        currentHand.middleFinger = leapFingerToObjFinger(middleType, middleBones, middleLength, middleWidth);
        currentHand.ringFinger = leapFingerToObjFinger(ringType, ringBones, ringLength, ringWidth);
        currentHand.pinkyFinger = leapFingerToObjFinger(pinkyType, pinkyBones, pinkyLength, pinkyWidth);
        ?
            return currentHand;
    }
    void Update()
    {
        ?
            //if (hand.IsLeft) { UnityEngine.Debug.Log("LeftHand ID: " + hand.Id); }
            //else { UnityEngine.Debug.Log("RightHand ID: " + hand.Id); }
            ?
            ?
            JsonHand currentJsonHand = leapHandToJsonHand(hand);
        ObjHand currentObjHand = leapHandToObjHand(hand);
        ?
            // [TODO] Deleted this part
            //      just for checking if "Distance" works well
            Gesture currentGesture = new Gesture();
        currentGesture.storedHand.copyFrom(currentObjHand);
        ?
            // To show in the Inspector window
            gestureHand.copyFrom(currentJsonHand);
        ?
            ?
            // Save Gesture when "Space Bar" is pressed
            if (Input.GetKeyDown(KeyCode.Space))
            {
                storedGesture.storedHand.copyFrom(currentObjHand);
                ?
                    // Save a .save file
                    BinaryFormatter bf = new BinaryFormatter();
                FileStream file = File.Create(GesturePath + @"\GestureData.save");
                bf.Serialize(file, storedGesture);
                ?
                    // Save a .json file
                    jsonGesture = JObject.FromObject(storedGesture);
                File.WriteAllText(GesturePath + @"\GestureData.json", jsonGesture.ToString());

                // Saving Completed
                UnityEngine.Debug.Log("Gesture Saved in.... " + GesturePath);
                ?
            }
        ?
            // [TODO] Delete this part
            //      just for checking if "Distance" works well
            if (File.Exists(GesturePath + @"\GestureData.save"))
            {
                UnityEngine.Debug.Log("Gesture Distance: " + Gesture.Distance(currentGesture, storedGesture));
            }
    }
}