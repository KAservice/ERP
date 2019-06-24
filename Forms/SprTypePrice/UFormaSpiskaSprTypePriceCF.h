#ifndef UFormaSpiskaSprTypePriceCFH                  
#define UFormaSpiskaSprTypePriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprTypePriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprTypePriceCF();                                                           
   ~TFormaSpiskaSprTypePriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
