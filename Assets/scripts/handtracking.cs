using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Leap.Unity;
using Leap;
using UnityEngine.UI;
using System.IO;


public class handtracking : MonoBehaviour
{
    CapsuleHand capsuleHand;
    Hand hand ;
    Vector3 firstVelocity = Vector3.zero;
    Vector3 firstposition =Vector3.zero;
    StreamWriter testStreamWriter;

    //델타타임으로 구한 가속도값
    public Vector3 acc;

    //leap 모듈로 측정한 속도, 위치
    public Vector3 vel;
    Vector3 pos;

    //델타타임으로 구한 속도값
    Vector3 exp;
    public Vector3 _palmnormal;

    private void Awake()
    {
        capsuleHand = gameObject.GetComponent<CapsuleHand>();
    }

    // Start is called before the first frame update
    [System.Obsolete]
    void Start()
    {
        

        //write a accleration data to text.txt
        //FileStream test = new FileStream(@"C:\Users\H-Tech Lab\Desktop\update_velocity.txt", FileMode.Create);
        FileStream test = new FileStream(@"C:\Users\H-Tech Lab\Desktop\testing_slowvel.txt", FileMode.Create);

        testStreamWriter = new StreamWriter(test);


        hand = capsuleHand.GetLeapHand();

    }

    // Update is called once per frame
    [System.Obsolete]
    void Update()
    {
        /*
        acc = (firstVelocity - UnityVectorExtension.ToVector3(hand.PalmVelocity)) / Time.deltaTime;
        firstVelocity = UnityVectorExtension.ToVector3(hand.PalmVelocity);
        vel = UnityVectorExtension.ToVector3(hand.PalmVelocity);
        pos = UnityVectorExtension.ToVector3(hand.PalmPosition);

        exp = (UnityVectorExtension.ToVector3(hand.PalmPosition) - firstposition)/Time.deltaTime;
        firstposition = UnityVectorExtension.ToVector3(hand.PalmPosition);

        testStreamWriter.WriteLine(vel.y + ":" + exp.y);

        Debug.Log(vel + " : " + exp);
        */
        //Debug.Log(hand.PalmNormal);
    }

    [System.Obsolete]
    private void FixedUpdate()
    {
        _palmnormal = UnityVectorExtension.ToVector3(hand.PalmNormal);
        //PalmVelocity unit : mm/s
        acc = (UnityVectorExtension.ToVector3(hand.PalmVelocity) - firstVelocity) / Time.fixedDeltaTime; //계산한 가속도
        firstVelocity = UnityVectorExtension.ToVector3(hand.PalmVelocity);

        vel = UnityVectorExtension.ToVector3(hand.PalmVelocity); //leap에서 측정한 속도
        pos = UnityVectorExtension.ToVector3(hand.PalmPosition); //leap에서 측정한 위치

        exp = (UnityVectorExtension.ToVector3(hand.PalmPosition) - firstposition) / Time.fixedDeltaTime; //leap에서 측정한 위치로 계산한 속도
        firstposition = UnityVectorExtension.ToVector3(hand.PalmPosition);


        //testStreamWriter.WriteLine(vel.y + ":" + exp.y);

        
        /*
        write a data to txt file
        testStreamWriter.WriteLine(acc.x + ":" +acc.y +":"+ acc.z);

        if (Input.GetKey(KeyCode.Space))
        {
            testStreamWriter.Close();
        }
        */

        /*
        //palmnormal과 velocity내적하여 손 앞뒤 방향 접근 구분
        if(Vector3.Dot(vel, UnityVectorExtension.ToVector3(hand.PalmNormal)) > 0)
        {
            Debug.Log("exact direction");
        }
        if(Vector3.Dot(vel, UnityVectorExtension.ToVector3(hand.PalmNormal)) < 0)
        {
            Debug.Log("wrong direction");
        }
        */
        
    }

}
