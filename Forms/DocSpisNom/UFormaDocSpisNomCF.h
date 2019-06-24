#ifndef UFormaDocSpisNomCFH                  
#define UFormaDocSpisNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocSpisNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocSpisNomCF();                                                           
   ~TFormaDocSpisNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
