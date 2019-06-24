#ifndef UFormaSpiskaSprMPrigCFH                  
#define UFormaSpiskaSprMPrigCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprMPrigCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprMPrigCF();                                                           
   ~TFormaSpiskaSprMPrigCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
