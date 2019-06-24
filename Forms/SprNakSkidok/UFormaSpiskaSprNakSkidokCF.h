#ifndef UFormaSpiskaSprNakSkidokCFH                  
#define UFormaSpiskaSprNakSkidokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprNakSkidokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprNakSkidokCF();                                                           
   ~TFormaSpiskaSprNakSkidokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
