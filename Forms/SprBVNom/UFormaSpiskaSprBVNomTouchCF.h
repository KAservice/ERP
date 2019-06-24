#ifndef UFormaSpiskaSprBVNomTouchCFH                  
#define UFormaSpiskaSprBVNomTouchCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprBVNomTouchCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprBVNomTouchCF();                                                           
   ~TFormaSpiskaSprBVNomTouchCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
