#ifndef UDMSprVidImageGrpCFH                  
#define UDMSprVidImageGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprVidImageGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprVidImageGrpCF();                                                           
   ~TDMSprVidImageGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
