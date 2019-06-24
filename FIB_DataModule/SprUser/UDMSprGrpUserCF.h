#ifndef UDMSprGrpUserCFH                  
#define UDMSprGrpUserCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprGrpUserCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprGrpUserCF();                                                           
   ~TDMSprGrpUserCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
