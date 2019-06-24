#ifndef UFormaSpiskaSprEdCFH                  
#define UFormaSpiskaSprEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprEdCF();                                                           
   ~TFormaSpiskaSprEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
