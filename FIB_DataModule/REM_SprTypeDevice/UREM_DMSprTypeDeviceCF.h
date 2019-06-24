#ifndef UREM_DMSprTypeDeviceCFH                  
#define UREM_DMSprTypeDeviceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprTypeDeviceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprTypeDeviceCF();                                                           
   ~TREM_DMSprTypeDeviceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
