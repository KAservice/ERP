#ifndef UFormaSpiskaSprScaleCFH                  
#define UFormaSpiskaSprScaleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprScaleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprScaleCF();                                                           
   ~TFormaSpiskaSprScaleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
