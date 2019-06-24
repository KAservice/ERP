#ifndef UDMSprVidImageCFH                  
#define UDMSprVidImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprVidImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprVidImageCF();                                                           
   ~TDMSprVidImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
