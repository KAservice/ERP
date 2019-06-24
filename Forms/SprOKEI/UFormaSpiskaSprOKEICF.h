#ifndef UFormaSpiskaSprOKEICFH                  
#define UFormaSpiskaSprOKEICFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprOKEICF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprOKEICF();                                                           
   ~TFormaSpiskaSprOKEICF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
