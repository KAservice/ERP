#ifndef UFormaElementaSprDepartmentCFH
#define UFormaElementaSprDepartmentCFH
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprDepartmentCF : public IkanClassFactory
{                                                                             
public:                                                                       
   TFormaElementaSprDepartmentCF();
   ~TFormaElementaSprDepartmentCF();
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
