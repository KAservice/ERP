#ifndef UFormaSpiskaSprVidImageCFH                  
#define UFormaSpiskaSprVidImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprVidImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprVidImageCF();                                                           
   ~TFormaSpiskaSprVidImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
