#ifndef UFormaElementaSprGrpUserCFH                  
#define UFormaElementaSprGrpUserCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprGrpUserCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprGrpUserCF();                                                           
   ~TFormaElementaSprGrpUserCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
