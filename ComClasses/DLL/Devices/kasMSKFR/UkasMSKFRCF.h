#ifndef UkasMSKFRCFH
#define UkasMSKFRCFH
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TkasMSKFRCF : public IkanClassFactory
{                                                                             
public:                                                                       
   TkasMSKFRCF();
   ~TkasMSKFRCF();
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif
