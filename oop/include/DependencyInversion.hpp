#pragma once

namespace solid
{
    namespace  d
    {
        namespace bad
        {
            class SoupRecipe 
            {
            public:
                SoupRecipe(){}
                ~SoupRecipe() {}
                void CookIt()
                {
                    cout << "Cook soup step 1" << endl;
                    cout << "Cook soup step 2" << endl;
                    cout << "Cook soup step 3" << endl;
                }
            };

            class Cook
            {
            public:
                Cook() {}
                ~Cook() {}

                void Setrecipe(SoupRecipe* rec)
                {
                    recipe_ = rec;
                }

                void Work()
                {
                    recipe_->CookIt();
                }

                SoupRecipe* recipe_;
            };
        }

        namespace ok
        {
            class IRecipe
            {
            public:
                virtual ~IRecipe() {}
                virtual void CookIt() = 0;
            };

            class SoupRecipe : public IRecipe
            {
            public:
                ~SoupRecipe() {}
                void CookIt() override
                {
                    cout << "Cook soup step 1" << endl;
                    cout << "Cook soup step 2" << endl;
                    cout << "Cook soup step 3" << endl;
                }
            };

            class SaladRecipe : public IRecipe
            {
            public:
                ~SaladRecipe() {}
                void CookIt() override
                {
                    cout << "Cook Salad step 1" << endl;
                    cout << "Cook Salad step 2" << endl;
                    cout << "Cook Salad step 3" << endl;
                }
            };

            class Cook
            {
            public:
                Cook() {}
                ~Cook() {}

                void SetRecipe(IRecipe* rec)
                {
                    recipe_ = rec;
                }

                void Work()
                {
                    if(recipe_ != nullptr)
                        recipe_->CookIt();
                }

                IRecipe* recipe_;
            };
        }
    }
}