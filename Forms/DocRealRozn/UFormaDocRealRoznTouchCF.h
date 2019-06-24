#ifndef UFormaDocRealRoznTouchCFH                  
#define UFormaDocRealRoznTouchCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRealRoznTouchCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRealRoznTouchCF();                                                           
   ~TFormaDocRealRoznTouchCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
