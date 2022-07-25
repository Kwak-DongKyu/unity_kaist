using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class objectinfo : MonoBehaviour
{
    public int inertia = 2;
    public int viscosity = 3;
    public int elasticity = 4;
    Vector3 initialposition;
    Quaternion initialrotate;

    // Start is called before the first frame update
    void Start()
    {
        initialposition = transform.position;
        initialrotate = Quaternion.Euler(transform.eulerAngles);
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Space))
        {
            gameObject.transform.position = initialposition;
            gameObject.transform.rotation = initialrotate;


        }
        }
    }
