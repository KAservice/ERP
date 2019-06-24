#ifndef UFormaElementaSprGrpVesNomCFH                  
#define UFormaElementaSprGrpVesNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprGrpVesNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprGrpVesNomCF();                                                           
   ~TFormaElementaSprGrpVesNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
