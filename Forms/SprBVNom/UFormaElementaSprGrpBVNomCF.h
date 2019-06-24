#ifndef UFormaElementaSprGrpBVNomCFH                  
#define UFormaElementaSprGrpBVNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprGrpBVNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprGrpBVNomCF();                                                           
   ~TFormaElementaSprGrpBVNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
