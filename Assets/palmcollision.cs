using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Leap.Unity;
using Leap;

public class palmcollision : MonoBehaviour
{
    //public CapsuleHand capsuleHand;
    //Hand hand;
    Vector3 velocity_1;

    public handtracking _handtracking;


    private void Awake()
    {
    }

    // Start is called before the first frame update
    [System.Obsolete]
    void Start()
    {
        //hand = capsuleHand.GetLeapHand();
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void FixedUpdate()
    {
        velocity_1 = _handtracking.vel;
    }
    [System.Obsolete]
    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag == "Object" && Vector3.Dot(velocity_1, _handtracking._palmnormal) > 0)
        {
            objectinfo _objectinfo = collision.gameObject.GetComponent<objectinfo>();
            Debug.Log(_objectinfo.viscosity +" , "+ _objectinfo.elasticity + " , " + _objectinfo.inertia);
            Debug.Log("물체와 충돌");
           
        }
    }
}
