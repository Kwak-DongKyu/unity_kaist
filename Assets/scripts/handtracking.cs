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

    //��ŸŸ������ ���� ���ӵ���
    public Vector3 acc;

    //leap ���� ������ �ӵ�, ��ġ
    public Vector3 vel;
    Vector3 pos;

    //��ŸŸ������ ���� �ӵ���
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
        acc = (UnityVectorExtension.ToVector3(hand.PalmVelocity) - firstVelocity) / Time.fixedDeltaTime; //����� ���ӵ�
        firstVelocity = UnityVectorExtension.ToVector3(hand.PalmVelocity);

        vel = UnityVectorExtension.ToVector3(hand.PalmVelocity); //leap���� ������ �ӵ�
        pos = UnityVectorExtension.ToVector3(hand.PalmPosition); //leap���� ������ ��ġ

        exp = (UnityVectorExtension.ToVector3(hand.PalmPosition) - firstposition) / Time.fixedDeltaTime; //leap���� ������ ��ġ�� ����� �ӵ�
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
        //palmnormal�� velocity�����Ͽ� �� �յ� ���� ���� ����
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
