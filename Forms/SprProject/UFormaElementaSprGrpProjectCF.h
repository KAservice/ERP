#ifndef UFormaElementaSprGrpProjectCFH                  
#define UFormaElementaSprGrpProjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprGrpProjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprGrpProjectCF();                                                           
   ~TFormaElementaSprGrpProjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
