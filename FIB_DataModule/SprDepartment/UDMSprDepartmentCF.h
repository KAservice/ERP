#ifndef UDMSprDepartmentCFH
#define UDMSprDepartmentCFH
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprDepartmentCF : public IkanClassFactory
{                                                                             
public:                                                                       
   TDMSprDepartmentCF();
   ~TDMSprDepartmentCF();
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
